class List: # создаём класс списка
    def __init__(self, value):
        self.value = value      # значение элемента
        self.next = None        # следующий элемент
        self.previous = None    # предыдущий элемент

    def Next(self): # вернуть следующий элемент
        return self.next

    def Previous(self): # вернуть предыдущий элемент
        return self.previous

    def First(self): # вернуть первый элемент
        node = self
        while node.previous:
            node = node.previous
        return node

    def Last(self): # вернуть последний элемент
        node = self
        while node.next:
            node = node.next
        return node

    def Nth(self, n): # вернуть n-й элемент
        node = self
        while node and n > 0:  # проходим список до n-го элемента
            node = node.next
            n -= 1
        if not node:
            raise ValueError("n is larger than the size of LinkedList.")
        return node

    def Append(self, item): # вставить элемент в конец списка
        node = self.Last()  # проходим до конца списка
        node.next = item    # вставляем элемент в конец
        node.next.previous = node # указываем, что предыдущий для последнего элемент

    def Insert(self, item, index=0): # вставить элемент в позицию n
        # получаем и сохраняем n-й элемент
        nth = self.Nth(index)
        previous = nth.previous
        node = List(item)

        last = node.Last()  # получаем последний эл-т
        last.next = nth     # вставляем n-й элемент после последнего
        nth.previous = last # связываем n-й элемент с последним

        # обновляем значения головного элемента, если это вставка в начало
        if previous:
            node.previous = previous
            previous.next = node

    def Remove(self): # удаление выбранного элемента
        if self.next: self.next.previous = self.previous
        if self.previous: self.previous.next = self.next

    def Value(self): # возврат значения элемента
        return self.value;

# MAIN

l = List(0) # заполняем список числами от 0 до 9
for n in range(1, 10):
    l.Append(List(n))

l.Insert(10, 5) # вставка
print(l.Nth(5).Value())

e = l.First() # печать/прохождение списка
while e:
    print(e.Value(), end=" ")
    e = e.Next()

print('')
