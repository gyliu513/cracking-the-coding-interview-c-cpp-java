class Card(object):
    def __init__(self, suit, value):
        self.value = value
        self.suit = suit

    def __eq__(self, card):
        return self.value == card.value and self.suit == card.suit

    def __gt__(self, card):
        if self.suit > card.suit:
            return True
        elif self.suit == card.suit:
            return self.value > card.value
        else:
            return False
