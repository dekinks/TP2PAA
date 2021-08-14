inversoes = 0
def merge(vetor, aux, inicio, meio, fim):

    global inversoes
    for i in range(inicio, fim + 1):
        aux[i] = vetor[i]

    j = inicio
    k = meio + 1

    for i in range(inicio, fim + 1):
        if j > meio:
            vetor[i] = aux[k]
            k += 1
        elif k > fim:
            vetor[i] = aux[j]
            j += 1
        elif aux[k] < aux[j]:
            vetor[i] = aux[k]
            k += 1
            inversoes += meio - inicio + 1
        else: 
            vetor[i] = aux[j]
            j += 1

def mergesort(vetor, aux, inicio, fim):

    if fim <= inicio:
        return
    meio = (inicio + fim) // 2

    mergesort(vetor, aux, inicio, meio)
    mergesort(vetor, aux, meio + 1, fim)
    merge (vetor, aux, inicio, meio, fim)

def main():

    vetor = input()

    while vetor != '0':
        global inversoes
        listaParaOrdenar = [int(i) for i in vetor.split(' ')]
        tamanho = listaParaOrdenar.pop(0)

        aux = [0] * len(listaParaOrdenar)
        mergesort(listaParaOrdenar, aux, 0, len(listaParaOrdenar) - 1)

        if inversoes % 2 == 0:
            print("Carlos")
        else:
            print("Marcelo")

        inversoes = 0
        vetor = input()

if __name__ == "__main__":
    main()