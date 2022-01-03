import os

def learndict(pword, word,check):
    if not check:
        f = open("dictionary.txt", "r")
        g = open("new_dictionary.txt", "w")
        while True:
            lines = f.readline().strip()
            if lines:
                (key, values) = lines.split(":")
                g.write(lines + "\n")
            else:
                g.write(pword + ": " + word + " 0")
                break
        f.close()
        g.close()
        os.remove("dictionary.txt")
        os.rename("new_dictionary.txt", "dictionary.txt")

    else:
        f = open("dictionary.txt", "r")
        g = open("new_dictionary.txt", "w")
        while True:
            lines = f.readline().strip()
            if lines:
                (key, values) = lines.split(":")
                if key == pword:
                    index = int(lines[-1])
                    g.write(lines + " " + word + " " + str(index + 1) + "\n")
                else:
                    g.write(lines + "\n")
            else:
                break

        f.close()
        g.close()
        os.remove("dictionary.txt")
        os.rename("new_dictionary.txt", "dictionary.txt")


mydic = {}
word = input("Enter word. $$ to terminate.")
sent = word
checkword = word
while not word == "$$":
    f = open("dictionary.txt", "r")
    for line in f:  # This loop updates the dictionary.txt file into mydic variable.
        (key, values) = line.split(":")
        temp = values.split()
        res = list(zip(temp[::2], temp[1::2]))
        mydic.update({key: res})
    f.close()
    if checkword in mydic:
        print(mydic[checkword])
        tno = input("Enter ints to add word from bank else enter space.")
        if not tno.isspace():
            print(sent + " " + mydic[checkword][int(tno)][0])
            sent = sent + " " + mydic[checkword][int(tno)][0]
            checkword = mydic[checkword][int(tno)][0]
            continue
    word = input("Enter word ")
    if not word == "$$":
        sent = sent + " " + word
        if not (word == "." or word == " " or checkword == "." or checkword == " "):
            check = True
            if checkword in mydic:
                max = mydic[checkword][-1][1]
                for count in range(int(max)+1):
                    if mydic[checkword][count][0] == word:
                        check = False
                        break
                if check:
                    learndict(checkword, word, True)
            else:
                learndict(checkword, word,False)
        checkword = word
    print(sent)
print(sent)
