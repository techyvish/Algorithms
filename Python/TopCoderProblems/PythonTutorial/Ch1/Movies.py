__author__ = 'Vishal'

 # List Operations
 # This methods will show list operations


def main():
    movies = ["Singhm 2", "Gajani", "Johny mera naam"]
    years = [2010, 2009, 1975]
    cast = ["Ajay", "Amir", "Devanand"]
    printmovies(movies)
    addnewcast("Salman", cast)
    removelastcast(cast)
    extendcast(cast, ["Shahrukh", "Anil"])
    removecast(cast, "Anil")
    insertcastat(cast, 0, "Salman")
    insertcastat(cast, 300, "Madhuri")
    insertyears(movies, years)


def printmovies(movies):
    print(movies)


def addnewcast(newcast, cast):
    cast.append(newcast)
    print(cast)


def removelastcast(cast):
    cast.pop()
    print(cast)


def extendcast(cast, listofnewcast):
    cast.extend(listofnewcast)
    print(cast)


def removecast(cast, name):
    cast.remove(name)
    print(cast)


def insertcastat(cast, pos, name):
    cast.insert(pos, name)
    print(cast)


def insertyears(movies, years):
    k = 0
    for i in range(len(movies) * 2):
        if i % 2 != 0:
            movies.insert(i, years[k])
            k += 1;
    print(movies)

main()