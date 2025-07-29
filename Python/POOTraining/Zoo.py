from SousClass import Lion



class Zoo:

    def __init__(self,NomZoo):
        self.NomZoo = NomZoo
        self.listAnimaux = []

    def ajouter_animal(self, animal):
        self.listAnimaux.append(animal)

    def faire_parler_tout_le_monde(self):
        for a in self.listAnimaux:
            print(f"{a.nom} dit : {a.parler()}")    

    def afficher_animaux(self):
        for a in self.listAnimaux:
            print(str(a))



lion = Lion(12,80,"yes")
lion.parler()

zoo = Zoo("test")
zoo.ajouter_animal(lion)
zoo.afficher_animaux()