#include "headers.h"

void getResults(Pass *key) {
        // printf("%s\n", key->appearList ? "true" : "false");
        float average = 0.0, length = 0.0;
        char *status = malloc(100);

        if (key->length >= 8) {
                length = 100;
        } else {
                length = (key->length * 100) / 8;
        }

        average = getAverage(key, length);
        getStatus(average, status);

        fprintf(stderr, "\n\n\tPassword: %s\n\n", key->password);
        fprintf(stderr, "Uso de Mayusculas:..............%s\n", key->upperCase ? "Si (100%)" : "No (0%)");
        fprintf(stderr, "Uso de Minusculas:..............%s\n", key->lowerCase ? "Si (100%)" : "No (0%)");
        fprintf(stderr, "Uso de Numeros:.................%s\n", key->numbers ? "Si (100%)" : "No (0%)");
        fprintf(stderr, "Uso de Caracteres Especiales:...%s\n", key->specialC ? "Si (100%)" : "No (0%)");
        fprintf(stderr, "Longitud:.......................%2d (%.0f%s)\n", key->length, length, "%");
        fprintf(stderr, "Aparece en Listas...............%s\n", key->appearList ? "Si (0%)" : "No (100%)");
        fprintf(stderr, "\nPromedio: %.2f (%s)\n\n", average, status);
}

float getAverage(Pass *key, float length) {
        float sum = 0.0, average = 0.0;

        if (key->upperCase) {
                sum += 100;
        }

        if (key->lowerCase) {
                sum += 100;
        }

        if (key->numbers) {
                sum += 100;
        }

        if (key->specialC) {
                sum += 100;
        }

        if (!key->appearList) {
                sum += 100;
        }

        sum += length;

        average = sum / 6;

        return average;
}

void getStatus(float average, char *status) {
        if (average >= 0 && average < 20) {
                strcpy(status,"Riesgo");
        } else if (average >= 20 && average < 39) {
                strcpy(status,"Carente");
        } else if (average >= 40 && average < 59) {
                strcpy(status,"Regular");
        } else if (average >= 60 && average < 89) {
                strcpy(status,"Bien");
        } else if (average >= 90 && average <= 100) {
                strcpy(status,"Excelente");
        }

        free(status);
}