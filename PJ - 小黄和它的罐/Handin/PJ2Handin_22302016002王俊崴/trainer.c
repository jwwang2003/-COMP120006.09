#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

#define MAP_W 12
#define MAP_H 12

struct Player {
    int y;
    int x;
};

// Array helpers
int randomInt(int x, int y) {
    if (x > y) return -1;
    return rand() % (y + 1 - x) + x;
}

int **init2DArray(int height, int width) {
    int **temp = (int**)malloc(height * sizeof(int*));
    for(int i = 0; i < height; ++i) {
        temp[i] = (int*)malloc(width * sizeof(int));

        for(int j = 0; j < width; ++j) {
            temp[i][j] = 0;
        }
    }

    return temp;
}

void dispose2DArray(int **temp, int height) {
    for(int i = 0; i < height; ++i) {
        free(temp[i]);
    }
    free(temp);

    return;
}

void copyStratTable(int **dest, int **source) {
    memcpy(dest, source, sizeof(int) * 200 * 243);
}

void copyMap(int **dest, int **source) {
    memcpy(dest, source, sizeof(int) * MAP_H * MAP_W);
}

// END

void generateRandomStrat(int **temp) {
    for(int i = 0; i < 200; ++i) {
        for(int j = 0; j < 243; ++j) {
            temp[i][j] = randomInt(0, 6);
        }
    }
    return;
}


// create a map with specified height and width
void createMap(int **grid) {
    // int **grid = (int**)malloc(MAP_H * sizeof(int*));

    for (int i = 0; i < MAP_H; ++i) {
        // grid[i] = malloc(MAP_W * sizeof(int));

        for(int j = 0; j < MAP_W; ++j) {
            grid[i][j] = 0;
        }

        for(int j = 0; j < MAP_W; ++j) {
            if (i == 0 || i == MAP_H - 1)
                grid[i][j] = 2;
            else if (j == 0 || j == MAP_W - 1)
                grid[i][j] = 2;
        }
    }

    int **av = (int**)malloc(100 * sizeof(int*));
    int i = 0;
    for(int y = 1; y < MAP_H - 1; ++y) {
        for(int x = 1; x < MAP_W - 1; ++x) {
            av[i] = (int*)malloc(2 * sizeof(int));
            av[i][0] = y;
            av[i][1] = x;
            i++;
        }
    }

    for(i = 0; i < 50; ++i) {
        int get = randomInt(0, 100 - i - 1);
        int *temp = av[get];
        av[get] = av[100 - i - 1];
        av[100 - i - 1] = temp;
    }

    for(i = 0; i < 50; ++i) {
        grid[av[i][0]][av[i][1]] = 1;
    }

    for(i = 0; i < 100; ++i) {
        free(av[i]);
//        printf("Freed: %d\n", i);
    }
    free(av);

    return;
}

// END
int *generateIntialStrat(void) {
    int *randomStrat = (int*)malloc(243 * sizeof(int));

    for(int i = 0; i < 243; ++i) {
        randomStrat[i] = randomInt(0,6);
    }

    return randomStrat;
}

int partition(int strategyTable[200][243], double *scores, int lt, int rt) {
    int pivot = scores[rt];
    int i = (lt - 1);

    for (int j = lt; j <= rt - 1; ++j) {
        if (scores[j] < pivot) {
            i++;
            double temp = scores[i];
            scores[i] = scores[j];
            scores[j] = temp;

            int t[243];
            memcpy(t, strategyTable[i], sizeof(int) * 243);
            memcpy(strategyTable[i], strategyTable[j], sizeof(int) * 243);
            memcpy(strategyTable[j], t, sizeof(int) * 243);
//            t = strategyTable[i];
//            strategyTable[i] = strategyTable[j];
//            strategyTable[j] = t;
        }
    }

    double temp = scores[i + 1];
    scores[i + 1] = scores[rt];
    scores[rt] = temp;

    int t[243];
    memcpy(t, strategyTable[i + 1], sizeof(int) * 243);
    memcpy(strategyTable[i + 1], strategyTable[rt], sizeof(int) * 243);
    memcpy(strategyTable[rt], t, sizeof(int) * 243);
//    int *t = strategyTable[i + 1];
//    strategyTable[i + 1] = strategyTable[rt];
//    strategyTable[rt] = t;

    return (i + 1);
}

void customQuickSort(int strategyTable[200][243], double *scores, int lt, int rt) {
    if(lt < rt) {
        int mid = partition(strategyTable, scores, lt, rt);
        customQuickSort(strategyTable, scores, lt, mid - 1);
        customQuickSort(strategyTable, scores, mid + 1, rt);
    }
}

int base3ToBase10(int arr[]) {
    int sum = 0;
    for(int i = 0; i < 5; ++i) {
        sum += arr[i] * pow(3, i + 1);
    }
    return sum;
}

int toDeci(int arr[], int base) {
    int len = 5;
    int power = 1; // Initialize power of base
    int num = 0;  // Initialize result
    int i;

    // Decimal equivalent is str[len-1]*1 +
    // str[len-2]*base + str[len-3]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be
        // less than number's base
        if (arr[i] >= base)
        {
            printf("Invalid Number");
            return -1;
        }

        num += arr[i] * power;
        power = power * base;
    }

    return num;
}

void getSurround(int **map, int playerY, int playerX, int *arr) {
    int up = playerY - 1;
    int down = playerY + 1;
    int left = playerX - 1;
    int right = playerX + 1;

    arr[0] = map[up][playerX];
    arr[1] = map[playerY][left];
    arr[2] = map[playerY][playerX];
    arr[3] = map[playerY][right];
    arr[4] = map[down][playerX];
}

int getNode(int **map, int y, int x) {
    return map[y][x];
}

int boundCheck(int playerY, int playerX) {
    return (((MAP_H - 2) >= playerY && playerY >= 1) && (MAP_W - 2) >= playerX && playerX >= 1);
}

// checks if the current node has jar before making a move
// if there is, remember to deduct points for not picking up
int hasJar(int **m, int y, int x) {
    if(getNode(m, y, x) == 1) {
        return 1;
    }
    return 0;
}

int pickUpJar(int **m, struct Player *p) {
    if(hasJar(m, p->y, p->x)) {
        m[p->y][p->x] = 0;    // set current node as empty after picking up
    } else return 0;    // return 0 indicating there was no jar

    // return 1 to indicate jar successfully picked up
    return 1;
}

// HELPER FUNCTIONS END

// Player control

// return 0 if player exceeds wall bounds, aka hits a wall
int movePlayer(int **m, struct Player *p, const int d[2]) {
    if(boundCheck(p->y + d[0], p->x + d[1])) {
        // new coordinates is within bounds
        p->y += d[0];
        p->x += d[1];
    } else return 0;

    return 1;
}

const int pDisplacement[4][2] = {
        {-1, 0},    // up
        {1, 0},     // down
        {0, -1},    // left
        {0, 1}      // right
};

int movePlayerUp(int **m, struct Player *p) {
//    int d[2] = {-1, 0};
    return movePlayer(m, p, pDisplacement[0]);
}

int movePlayerDown(int **m, struct Player *p) {
//    int d[2] = {1, 0};
    return movePlayer(m, p, pDisplacement[1]);
}

int movePlayerLeft(int **m, struct Player *p) {
//    int d[2] = {0, -1};
    return movePlayer(m, p, pDisplacement[2]);
}

int movePlayerRight(int **m, struct Player *p) {
//    int d[2] = {0, 1};
    return movePlayer(m, p, pDisplacement[3]);
}

int movePlayerRandom(int **m, struct Player *p) {
    int i = randomInt(1, 6);

    switch (i) {
        case 1:
            return movePlayerUp(m, p);
        case 2:
            return movePlayerDown(m, p);
        case 3:
            return movePlayerLeft(m, p);
        case 4:
            return movePlayerRight(m, p);
        case 5:
            return 1;
        case 6:
            return pickUpJar(m, p);
    }

    return 0;
}

// END

void generateOffspring(int *par1, int *par2, int *child1, int *child2) {
    int i = 0;
    int j = 0;
    while(i < 243) {
        if(i > (j + 1)*60 && (j + 2)*60 < 243) {
            ++j;
        }

        int shouldMutate = randomInt(0, 800) == 0;
        if(shouldMutate) {
            if(randomInt(0, 1) == 0) {
                child1[i] = randomInt(0, 6);
            }
            if(randomInt(0, 1) == 1) {
                child2[i] = randomInt(0, 6);
            }
        } else {
            if(j % 2 == 0) {
                child1[i] = par1[i];
                child2[i] = par2[i];
            } else {
                child1[i] = par2[i];
                child2[i] = par1[i];
            }
        }

        ++i;
    }
}

void printMap(int **map, int y, int x) {
    for(int i = 0; i < 12; ++i) {
        for(int j = 0; j < 12; ++j) {
            if(i == y && j == x) {
                printf("!");
            } else {
                switch(map[i][j]) {
                    case 0:
                        printf(" ");
                        break;
                    case 1:
                        printf("@");
                        break;
                    case 2:
                        printf("#");
                }
            }
            printf(" ");
        }
        printf("\n");
    }
}

int autoRun(int **map, int *strat) {
    struct Player *p = (struct Player*)malloc(sizeof (struct Player));
    p->y = 1;
    p->x = 1;
    int score = 0;

    // run a total of 200 times (make 200 moves)
    for(int i = 0; i < 200; ++i) {
        int arr[5] = { 0 };
        getSurround(map, p->y, p->x, arr);
        int getStrat = toDeci(arr, 3);

        switch(strat[getStrat]) {
            case 0:
                if(movePlayerRandom(map, p) == 0) {
                    score -= 5;
                }
                break;
            case 1:
                if(movePlayerUp(map, p) == 0) {
                    score -= 5;
                }
                break;
            case 2:
                if(movePlayerDown(map, p) == 0) {
                    score -= 5;
                }
                break;
            case 3:
                if(movePlayerLeft(map, p) == 0) {
                    score -= 5;
                }
                break;
            case 4:
                if(movePlayerRight(map, p) == 0) {
                    score -= 5;
                }
                break;
            case 5:
//                game->score -= 1;
                break;
            case 6:
                if(pickUpJar(map, p)) {
                    score += 10;
                } else {
                    score -= 2;
                }
                break;
            default:
                printf("INVALID! %d\n", getStrat);
                printMap(map, 1, 1);
                break;
        }
    }

    return score;
}

int strategyTable[200][243] = { 0 };

int **getEmptyStrategyTable(void) {
    int **table = (int**)malloc(200 * sizeof(int*));
    for(int i = 0; i < 200; ++i) {
        table[i] = (int*)malloc(243 * sizeof(int));
        for (int j = 0; j < 243; ++j) {
            table[i][j] = 0;
        }
    }
    return table;
}

void freeStrategyTable(int **strategyTable) {
    for(int i = 0; i < 200; ++i) {
        free(strategyTable[i]);
    }
    free(strategyTable);
    return;
}

// favors top performers (result is sorted from lowest to highest, therefore favors last)
int biasedRandChicken(void) {
    int randChick = randomInt(0, 20099);
//    floor((-1 + sqrtf(1 + 8*randChick))/2.0);
//    floor((2.0*randChick)/200);
    int chickID = floor((-1 + sqrtf(1 + 8 * randChick))/2.0);
    return chickID;
}

void train(double *scores) {
    for(int i = 0; i < 200; ++i) {
        for(int j = 0; j < 100; ++j) {
            int **temp = init2DArray(MAP_H, MAP_W);
            createMap(temp);
            scores[i] += autoRun(temp, strategyTable[i]);

            for(int c = 0; c < MAP_H; ++c) {
                free(temp[c]);
            }
            free(temp);
        }

        scores[i] = scores[i] / 100.0;
    }

    customQuickSort(strategyTable, scores, 0, 200 - 1);

    int **newStrategyTable = getEmptyStrategyTable();
    int newStratCounter = 0;

    // proceed with 95 tries in selecting two chickens and
    // geneating two offspring from those two chickens
    for (int counter = 0; counter < 95; ++counter) {
        int chick1 = biasedRandChicken();
        int chick2;
        do {
            chick2 = biasedRandChicken();
        } while (chick1 == chick2);

        generateOffspring(strategyTable[chick1],
                          strategyTable[chick2],
                          newStrategyTable[newStratCounter],
                          newStrategyTable[newStratCounter + 1]
        );

        newStratCounter += 2;
    }

    for(; newStratCounter < 200; ++newStratCounter) {
        for(int j = 0; j < 243; ++j) {
            newStrategyTable[newStratCounter][j] = strategyTable[newStratCounter][j];
        }
    }

    for(int i = 0; i < 200; ++i) {
        for(int j = 0; j < 243; ++j) {
            strategyTable[i][j] = newStrategyTable[i][j];
        }
    }
    freeStrategyTable(newStrategyTable);

    return;
}


int main(void) {
//    long currentSeed = 1672045933;
//    long currentSeed = 1672544497;  // good ~110
//    long currentSeed = 1672045933;
//    long currentSeed = 1672567538;
//    long currentSeed = 1672564610; // better 170
//    long currentSeed = 1672568622; // 250
//    long currentSeed = 5;

    FILE *csvFile, *seedFile, *stratFile;

    int flag = 1;

    while(flag) {
        long currentSeed = 1672600977;
        printf("%ld\n", currentSeed);
        srand(currentSeed);

        csvFile = fopen("./results.csv", "w+");
        fprintf(csvFile, "Generation, Average Score\n");

        seedFile = fopen("./seed.txt", "w+");
        fprintf(seedFile, "%ld", currentSeed);
        fclose(seedFile);

        stratFile = fopen("./stratFile.txt", "w+");

//    int **chickStrategy = (int**)malloc(200 * sizeof(int*));
//    for(int i = 0; i < 200; ++i) {
//        chickStrategy[i] = (int*)malloc(243 * sizeof(int));
//        for(int j = 0; j < 243; ++j) chickStrategy[i][j] = 0;
//    }

        for (int i = 0; i < 200; ++i) {
            for (int j = 0; j < 243; ++j) {
                strategyTable[i][j] = randomInt(0, 6);
            }
        }

        double runtimeResults[200] = {0};

        // driver code
        for (int i = 0; i < 200; ++i) runtimeResults[i] = 0;

        double avg;
        for (int i = 0; i < 1000; ++i) {
            avg = 0;
            train(runtimeResults);
            for (int c = 0; c < 200; ++c) {
                avg += runtimeResults[c];
            }
            avg /= 200.0;

//            printf("Generation %d | Average Score %lf | High %lf\n", i + 1, avg, runtimeResults[199]);
            printf("g_%d_ avg_%lf\n", i + 1, avg, runtimeResults[199]);
            fprintf(csvFile, "%d, %lf\n", i + 1, avg);

        }
        if(avg > 320) flag = 0;

        customQuickSort(strategyTable, runtimeResults, 0, 200 - 1);

//        printf("%f\n", runtimeResults[199]);
        for (int j = 0; j < 243; ++j) {
            fprintf(stratFile, "%d", strategyTable[199][j]);
        }

        fclose(csvFile);
        fclose(stratFile);
    }

    return 0;
}