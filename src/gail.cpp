/*
 Gail - budget in 15 minutes or less.

 Usage:
    $ gail add 210393.77                # add latest salary
    Latest salary added!
    $ gail salary                       # show list of salary added
    Php 210,393.77 - 19:32 5-3-2020
    $ gail set "Enjoy Fund" 15%         # set "enjoy fund" by 15%
    $ gail set Electricity 1350         # set electricity to 1350
    $ gail budget                       # show budget breakdown using next salary in queue
    Here's your budget breakdown
        Salary:             210,393.77
        Enjoy Fund:          31,559.06
        Electricity:          1,350.00

        Remaining balance:  178,834.70

*/

#include <getopt.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <queue>


#define APP_NAME    "gail"
#define VERSION     "0.1.1"

using namespace std;

// global variables
static queue<double> BUDGET;

// function declaration
void add_budget(double);
void remove_budget(void);
void count_budget(void);
void show_help(string name);
void compute_simple_budget(string amount_arg);


int main(int argc, char **argv) {

    int opt;
    int index;
    double amount;

    while ((opt = getopt(argc, argv, "-a:rcv")) != -1)
    {
        switch (opt)
        {
            case 1:

                // test compute_simple_budget
                compute_simple_budget(optarg);

                if (strcmp(optarg, "add") == 0) {
                    printf("%s\n", argv[2]);
                }
                // [] TODO: add 'set'
                // [] TODO: add 'budget'
                break;
            case 'a':   // --add
                amount = stod(optarg);
                add_budget(amount);
                printf("%f added!\n", amount);
                break;
            case 'r':   // --remove
                remove_budget();
                break;
            case 'c':   // --check or count budget
                count_budget();
                break;
            case 'v':
                printf("%s\n", VERSION);
                break;
            case '?':
                printf("unknown option %c\n\n", optopt);
                show_help(APP_NAME);
                return 1;
            default:
                printf("hello");
         }
    }

    // if the user just type gail
    if (optind == 1)
    {
        show_help(APP_NAME);
    }


    return 0;
}


// function definition
void add_budget(double latest_salary)
{
    BUDGET.push(latest_salary);
}

void remove_budget()
{
    BUDGET.pop();
}

void count_budget()
{
    printf("%ld\n", BUDGET.size());
}

void show_help(string name)
{
    cerr << "Gail - budget in 15 minutes or less.\n\n"
         << "Usage:\n"
         << "\t$ " <<  name << "\n"
         << "\t" <<"// todo\n"
         << "Options:\n"
         << "\t -h, --help\t\tDisplay this help message.\n"
         << "\t -v, --version\t\tDisplay application version information.\n"
         << endl;
}


void compute_simple_budget(string amount_arg)
{
    double amount = 0;
    double savings = 0;
    double balance = 0;
    
    double enjoy_fund;
    double gerona_fund;
    double gift_fund;
    double business_fund;
    double cash_fund;

    double food;
    
    double savings_rate = 0.7;
    double enjoy_fund_rate = 0.1428;
    double gerona_fund_rate = 0.1428;
    double gift_fund_rate = 0.1428;
    double business_fund_rate = 0.1;
    double cash_fund_rate = 0.6144;

    amount = stod(amount_arg);
    savings = amount * savings_rate;
    
    // compute each fund based on savings
    enjoy_fund = savings * enjoy_fund_rate;
    gerona_fund = (savings * gerona_fund_rate) / 2;
    gift_fund = (savings * gift_fund_rate) / 2;
    business_fund = savings * business_fund_rate;
    cash_fund = savings * cash_fund_rate - 3000;

    // compute expenses
    food = 3000;

    balance = amount - (enjoy_fund + gerona_fund + gift_fund + business_fund + cash_fund + food) - 3000;

    cout << "Allocation" << setw(26) << "Amount" << "\n\n";
    printf("Enjoy Fund: %*.2f\n", 25, enjoy_fund);
    printf("Gerona Foundation Fund: %*.2f\n", 13, gerona_fund);
    printf("Gift Fund: %*.2f\n", 26, gift_fund);
    printf("Business Machine Fund: %*.2f\n", 14, business_fund);
    printf("Cash Machine Fund: %*.2f\n", 18, cash_fund);
    printf("\n");
    printf("Food: %*.2f\n", 31, food);
    printf("\n");
    printf("Remaining: %*.2f\n", 26, balance);
}
