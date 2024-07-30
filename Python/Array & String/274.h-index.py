class Solution(object):
    def hIndex(self, citations):
        citations.sort()
        citations.reverse()

        x = 0
        n = len(citations)

        if n <= 1:
            result = citations[0]
            return int(str(result)[0])
            
        for i in range(n):
            if citations[i] >= i + 1:
                x = i + 1
        
        return x

# Créez une instance de la classe Solution
solution = Solution()

# Appelez la méthode hIndex sur l'instance
citations = [6, 5, 3, 1, 0]
print("Attendu: 3, Obtenu:", solution.hIndex(citations))
