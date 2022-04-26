### SECTION vs TASKS

- Tenho um programa sequencial e quero paralelizar -> SECTIONS
- Dentro de uma thread preciso chamar uma parte menor dela-> TASKS


- Section é atribuída a uma thread exclusiva, tasks não. Se não travar na master, elas podem ser execuutadas N vezes (N= número de threads).

- omp critical -> Todas as threads executam, uma de cada vez.
- omp single -> não recomendado para tasks. Ele tenta ammarar tudo na mesma thread, gerando um processo sequencial. Indicado usar o master. 
- omp taskwait -> quando preciso esperar todas as tasks executarem para retornar um resultado.

                                          -------
                                fork    /         \ join
                                ------ -- -- -- -- -------         
                                        \         /
                                          -------
