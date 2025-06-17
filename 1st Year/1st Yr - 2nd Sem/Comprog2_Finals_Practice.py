class Methods:
    def iSorted(self, arr, s):
        for i in range(s - 1):
            if arr[i] < arr[i + 1]:
                return False
        return True

    def rOccur(self, arr, n, i):
        if i < 0:
            return 0
        if arr[i] == n:
            return 1 + self.rOccur(arr, n, i - 1)
        else:
            return self.rOccur(arr, n, i - 1)

    def iSmall(self, arr, s):
        sm = arr[0]
        for i in range(s - 1):
            if arr[i] < arr[i + 1]:
                sm = arr[i]
            else:
                sm = arr[i + 1]
        return sm

    def rSmall(self, arr, s):
        if s == 1:
            return arr[0]
        sm = self.rSmall(arr, s - 1)
        if arr[s - 1] < sm:
            return arr[s - 1]
        else:
            return sm

    def iPal(self, arr, s):
        for i in range(s // 2):
            if arr[i] != arr[s - 1 - i]:
                return False
        return True

    def rPal(self, arr, i, s):
        if i >= s:
            return True
        if arr[s - 1] != arr[i]:
            return False
        else:
            return self.rPal(arr, i + 1, s - 1)


if __name__ == "__main__":
    print("\nPractice Problems")
    m = Methods()
    arr = [76, 57, 54, 54, 32]
    arrp = [5, 4, 3, 2, 2, 3, 4, 5]
    s = len(arr)
    s2 = len(arrp)

    if m.iSorted(arr, s):
        print("1. Sorted in descending order")
    else:
        print("1. Sorted not in descending order")

    n = 54
    ocr = m.rOccur(arr, n, s - 1)
    print(f"2. Number of occurrence/s of {n} is: {ocr}")

    sm = m.iSmall(arr, s)
    print(f"3. The smallest element in the array is: {sm}")
    smr = m.rSmall(arr, s)
    print(f"4. The smallest element in the array is: {smr}")

    if m.iPal(arrp, s2):
        print("5. Array is palindrome")
    else:
        print("5. Array is not palindrome")

    if m.rPal(arrp, 0, s2):
        print("6. Array is palindrome\n")
    else:
        print("6. Array is not palindrome\n")

