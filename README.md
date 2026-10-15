
# Studentų pažymių skaičiavimo programa

## v0.3 – vector ir list spartos tyrimas

Palyginau vector ir list konteinerių spartą apdorojant 1000, 10000, 100000, 1000000 ir 10000000 studentų failus.

Kiekvieną failą su abiem konteineriais išbandžiau po 3 kartus. Visuose bandymuose studentai buvo skirstomi pagal galutinio pažymio vidurkį ir rūšiuojami pagal pavardę.

### Kompiuterio parametrai

- CPU: AMD Ryzen 5 220
- RAM: 16 GB DDR5
- SSD: 480 GB NVMe

### Testavimo rezultatai

Lentelėje pateikti 3 bandymų vidurkiai sekundėmis.

| Studentai | Konteineris | Skaitymas | Skirstymas | Rūšiavimas | Rašymas |
|---|---|---:|---:|---:|---:|
| 1000 | vector | 0.0154 | 0.0007 | 0.0030 | 0.0214 |
| 1000 | list | 0.0062 | 0.0006 | 0.0006 | 0.0031 |
| 10000 | vector | 0.0402 | 0.0061 | 0.0442 | 0.0125 |
| 10000 | list | 0.0411 | 0.0044 | 0.0053 | 0.0143 |
| 100000 | vector | 0.4275 | 0.0523 | 0.5872 | 0.1162 |
| 100000 | list | 0.4517 | 0.0483 | 0.0800 | 0.1331 |
| 1000000 | vector | 3.6866 | 0.6582 | 6.1325 | 1.0118 |
| 1000000 | list | 3.7840 | 0.5130 | 1.1225 | 1.5772 |
| 10000000 | vector | 48.5395 | 5.0087 | 65.8691 | 9.6691 |
| 10000000 | list | 49.6147 | 4.4198 | 10.8572 | 11.0980 |

### Išvados

Atliekant bandymus pastebėjau, kad list konteineris gerokai greičiau rūšiuoja studentus, ypač esant dideliam jų skaičiui. Tuo tarpu vector dažniausiai buvo greitesnis skaitant ir rašant failus.

Pagal bendrą apdorojimo laiką mano programoje geresnius rezultatus parodė list konteineris.


## Testavimo nuotraukos

### 1000 studentų

**Vector**

![Vector 1000](images/vector_1000.png)

**List**

![List 1000](images/list_1000.png)

### 1 000 000 studentų

**Vector**

![Vector 1000000](images/vector_1000000.png)

**List**

![List 1000000](images/list_1000000.png)

### 10 000 000 studentų

**Vector**

![Vector 10000000](images/vector_10000000.png)

**List**

![List 10000000](images/list_10000000.png)

