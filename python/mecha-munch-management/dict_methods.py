"""Functions to manage a users shopping cart items."""


def add_item(current_cart: dict[str, int], items_to_add: tuple[str]):
    """Add items to shopping cart.

    :param current_cart: dict - the current shopping cart.
    :param items_to_add: iterable - items to add to the cart.
    :return: dict - the updated user cart dictionary.
    """

    for item in items_to_add:
        current_cart.setdefault(item, 0)
        current_cart[item] += 1

    return current_cart


def read_notes(notes):
    """Create user cart from an iterable notes entry.

    :param notes: iterable of items to add to cart.
    :return: dict - a user shopping cart dictionary.
    """

    out = {}
    add_item(out, notes)
    return out


def update_recipes(
    ideas: dict[str, dict[str, int]], recipe_updates: list[tuple[str, dict[str, int]]]
):
    """Update the recipe ideas dictionary.

    :param ideas: dict - The "recipe ideas" dict.
    :param recipe_updates: dict - dictionary with updates for the ideas section.
    :return: dict - updated "recipe ideas" dict.
    """

    for recipe in recipe_updates:
        recipename = recipe[0]
        ideas[recipename] = recipe[1]

    return ideas


def sort_entries(cart):
    """Sort a users shopping cart in alphabetically order.

    :param cart: dict - a users shopping cart dictionary.
    :return: dict - users shopping cart sorted in alphabetical order.
    """

    return dict(sorted(cart.items()))


def send_to_store(cart: dict[str, int], aisle_mapping: dict[str, tuple[str, bool]]):
    """Combine users order to aisle and refrigeration information.

    :param cart: dict - users shopping cart dictionary.
    :param aisle_mapping: dict - aisle and refrigeration information dictionary.
    :return: dict - fulfillment dictionary ready to send to store.
    """

    return {
        item: [count, *aisle_mapping[item]]
        for item, count in sorted(cart.items(), reverse=True)
    }


def update_store_inventory(
    fulfillment_cart: dict[str, list[int, str, bool]],
    store_inventory: dict[str, list[int, str, bool]],
):
    """Update store inventory levels with user order.

    :param fulfillment cart: dict - fulfillment cart to send to store.
    :param store_inventory: dict - store available inventory
    :return: dict - store_inventory updated.
    """

    return {
        item: [
            (count - fulfillment_cart.get(item, [0])[0]) or "Out of Stock",
            aisle,
            freeze,
        ]
        for item, (count, aisle, freeze) in store_inventory.items()
    }
