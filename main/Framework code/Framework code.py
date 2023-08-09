from enum import IntEnum
import socket, errno

def to_bytes_fn(n, length):
    return bytes((n >> i * 8) & 0xFF for i in (range(length)))

class Partition_ID(IntEnum):
    Training_Partition = 1

class Training_Partition_Commands(IntEnum):
    DataLoopback = 1

class Generic_UDP():
    def __init__(self,client_server = 0,IP = "127.0.0.1",server_port = 2000, client_port = 2001):

        # Sockets
        self.address_server = (IP, server_port)
        self.address_client = (IP, client_port)
        self.socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
        self.socket_recv = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
        self.flag_server = client_server

        # Message data to send
        self.message_size = 0
        self.message_data = None
        self.payload = "Testing\n"

        # Message data to receive
        self.rcvd_payload = []
        self.rcvd_data_raw = 0
        self.message_received = False

        # ID data
        self.partition_ID = Partition_ID.Training_Partition
        self.command_ID = Training_Partition_Commands.DataLoopback

        self.rcvd_partition_ID = -1
        self.rcvd_command_ID = -1


        try:
            self.socket_recv.bind(self.address_client)
        except socket.error as e:
            if e.errno != errno.EADDRINUSE:
                print(e)

    def close(self):
        self.socket.close()
        self.socket_recv.close()

    def send_message(self):
        self.message_received = False
        self.build_message()
        self.socket.sendto(self.message_data,self.address_server)

    def build_message(self):
        self.message_data = to_bytes_fn(self.partition_ID,2)
        self.message_data += to_bytes_fn(self.command_ID,2)
        self.message_data += bytes(self.payload, 'utf-8')
        self.message_size = len(self.message_data) + 4
        self.message_data = to_bytes_fn(self.message_size,4) + self.message_data

    def message_receive(self):
        self.socket_recv.settimeout(1)
        try:
            self.rcvd_data_raw, address = self.socket_recv.recvfrom(2001)
        except:
            self.message_received = False
            print("Didn't receive word in time")
            return False

        self.message_received = True
        return True

    def SR_Message(self):
        attempts = 0
        max_attempts = 3
        while (not self.message_received and attempts < max_attempts):
            if (not self.message_receive()):
                attempts = attempts + 1
                continue
            else:

                self.socket_recv.settimeout(None)

                # Get partition id and command id
                partition_id = int.from_bytes(self.rcvd_data_raw[4:6], 'little')
                command_id = int.from_bytes(self.rcvd_data_raw[6:8], 'little')

                # Check if sent IDs match received IDs and return False if they don't
                if (partition_id != self.partition_ID or command_id != self.command_ID):
                    print(f"The partition id{partition_id} or the command id{command_id} dont match requested\
                            partition id {self.partition_ID} or the command id {self.command_ID}")
                    return False

                # Set class values to the received data
                print("The received partition id and the command id match requested partition id and command id")
                self.rcvd_command_ID = command_id
                self.rcvd_partition_ID = partition_id
                self.rcvd_payload = self.rcvd_data_raw[8:]

                return True

        print("Timeout expired")
        if self.message_received == False:
            return False

