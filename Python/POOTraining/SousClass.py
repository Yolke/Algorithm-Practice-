from Animal import Animal


class Lion(Animal):
    def __init__(self,age,poids,territoire):
        Animal.__init__(self,age,poids)
        self.territoire = territoire
    
    def parler(self):
        print("Roaaar")

class Ours(Animal):
    def __init__(self,age,poids,hiberne):
        Animal.__init__(self,age,poids)
        self.hiberne = hiberne
    
    def parler(self):
        print("Grrrr")

class Perroquet(Animal):
    def __init__(self,age,poids,couleur):
        Animal.__init__(self,age,poids)
        self.couleur = couleur
    
    def parler(self):
        print("Roaaar")