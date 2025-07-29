class Animal:
    def __init__(self,age,poids):
        self.age = age;
        self.poids = poids;
    
    def __str__(self):
        return f"Animal - Âge: {self.age} ans, Poids: {self.poids} kg"
