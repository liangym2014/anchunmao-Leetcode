# https://leetcode.com/problems/seat-reservation-manager/

class SeatManager:

    def __init__(self, n: int):
        self.available_seats = list(range(1, n + 1))
        

    def reserve(self) -> int:
        return heappop(self.available_seats)


    def unreserve(self, seatNumber: int) -> None:
        heappush(self.available_seats, seatNumber)
