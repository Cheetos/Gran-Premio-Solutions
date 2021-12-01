def place_order(amount):
    if amount >= 500:
        return amount - 100
    return amount


def main():
    book_prices = [int(num) for num in input().split()]

    order_1 = place_order(book_prices[0] + book_prices[1] + book_prices[2])

    order_2 = place_order(book_prices[0] + book_prices[1]) + place_order(book_prices[2])
    order_2 = min(order_2, place_order(book_prices[0] + book_prices[2]) + place_order(book_prices[1]))
    order_2 = min(order_2, place_order(book_prices[1] + book_prices[2]) + place_order(book_prices[0]))

    order_3 = place_order(book_prices[0]) + place_order(book_prices[1]) + place_order(book_prices[2])

    print(min([order_1, order_2, order_3]))


if __name__ == '__main__':
    main()
