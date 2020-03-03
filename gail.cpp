/*
 * test budget
 *
 * Usage:
 *  > budget --add 73829.72 // add latest salary to budget
 *  > budget --breakdown    // savings, expenses, others, etc.
 *  > budget --actions      // withdrawal, transfer
 * // add new breakdown
 *  > budget --new "enjoy fund" 0.1

*/

#include <getopt.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <queue>


#define APP_NAME    "gail"
#define VERSION     "0.1"

using namespace std;

// global variables
static queue<double> BUDGET;

// function declaration
void add_budget(double);
void remove_budget(void);
void count_budget(void);
void show_help(string name);


int main(int argc, char **argv) {

    int opt;
    int index;
    double amount;

    // [] TODO: learn how to add 1-word commands
    while ((opt = getopt(argc, argv, "-a:rcv")) != -1) {
        switch (opt) {
            case 1:
                if (argv[optind] == "check") {
                    printf("check");
                }
//                printf("something unexpected happend %s\n", optarg);
                for (index = optind; index < argc; index++) {
                    printf("%s", argv[index]);
                }
                break;
            case 'a':   // --add
                amount = stod(optarg);
                add_budget(amount);
                printf("%f added!\n", amount);
                break;
            case 'r':   // --remove
                remove_budget();
                break;
            case 'c':   // --check or count budgetf
                count_budget();
                break;
            case 'v':
                printf("%s\n", VERSION);
                break;
            case '?':
                printf("unknown option %c\n\n", optopt);
                show_help(APP_NAME);
                return 1;
        }
    }

    return 0;
}


// function definition
void add_budget(double latest_salary) {
    BUDGET.push(latest_salary);
}

void remove_budget() {
    BUDGET.pop();
}

void count_budget() {
    printf("%ld\n", BUDGET.size());
}

void show_help(string name)
{
    cerr << "Gail - you simple budgeting app.\n\n"
         << "Usage:\n"
         << "\t$ " <<  name << "\n"
         << "\t" <<"// todo\n"
         << "Options:\n"
         << "\t -h, --help\t\tDisplay this help message.\n"
         << "\t -V, --version\t\tDisplay application version information.\n"
         << endl;
}
