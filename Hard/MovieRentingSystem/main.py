from sortedcontainers import SortedList

class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.unrented = {}
        self.rented = SortedList()
        self.movie_prices = {}
        for shop, movie, price in entries:
            self.movie_prices[(shop, movie)] = price
            if movie not in self.unrented:
                self.unrented[movie] = SortedList()
            self.unrented[movie].add((price, shop))

    def search(self, movie: int) -> List[int]:
        unrented_movies = self.unrented.get(movie, [])[:5]
        return [shop for _, shop in unrented_movies]

    def rent(self, shop: int, movie: int) -> None:
        price = self.movie_prices[(shop, movie)]
        self.unrented[movie].remove((price, shop))
        self.rented.add((price, shop, movie))

    def drop(self, shop: int, movie: int) -> None:
        price = self.movie_prices[(shop, movie)]
        self.rented.remove((price, shop, movie))
        self.unrented[movie].add((price, shop))

    def report(self) -> List[List[int]]:
        return [[shop, movie] for _, shop, movie in self.rented[:5]]