def registrar_vertices(vertices):
    print("Ingrese los vértices (X Y Z) separados por espacios. Ingrese '-1' para finalizar.")
    while True:
        entrada = input("> ")
        if entrada == "-1":
            break
        try:
            x, y, z = map(float, entrada.split())
            vertices.append((x, y, z))
        except ValueError:
            print("Entrada inválida. Asegúrese de ingresar tres números separados por espacios.")


def registrar_caras(caras, vertices):
    if not vertices:
        print("Debe registrar vértices antes de agregar caras.")
        return
    
    print("Ingrese los índices de los vértices para cada cara separados por espacios. Ingrese '-1' para finalizar.")
    while True:
        entrada = input("> ")
        if entrada == "-1":
            break
        
        try:
            indices = list(map(int, entrada.split()))
            if -1 in indices:  
                indices = [i for i in indices if i != -1]  # Eliminar el `-1` antes de registrar la cara

            if not indices:
                break  # Si no quedan índices válidos, salir del loop

            if all(0 <= i < len(vertices) for i in indices):
                caras.append(indices)
            else:
                print("Error: Un índice está fuera del rango de vértices registrados.")
        except ValueError:
            print("Entrada inválida. Asegúrese de ingresar números enteros separados por espacios.")


def imprimir_estructura(vertices, caras):
    if vertices:
        print("\nEstructura de Vértices:")
        for i, (x, y, z) in enumerate(vertices):
            print(f"V{i}: ({x}, {y}, {z})")
    else:
        print("No hay vértices registrados.")

    if caras:
        print("\nEstructura de Caras:")
        for i, cara in enumerate(caras):
            print(f"F{i}: {' '.join(map(str, cara))}")
    else:
        print("No hay caras registradas.")


def main():
    vertices = []
    caras = []

    while True:
        print("1. Registrar Vértices")
        print("2. Registrar Caras")
        print("3. Imprimir la Figura")
        print("4. Salir")
        opcion = input("Seleccione una opción: ")

        if opcion == "1":
            registrar_vertices(vertices)
        elif opcion == "2":
            registrar_caras(caras, vertices)
        elif opcion == "3":
            imprimir_estructura(vertices, caras)
        elif opcion == "4":
            print("Saliendo del programa.")
            break
        else:
            print("Opción inválida. Intente de nuevo.")


if __name__ == "__main__":
    main()
