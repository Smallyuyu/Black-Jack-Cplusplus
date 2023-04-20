#include<iostream>
#include<vector>
using namespace std;
#ifndef PLAYERPOINT_H_
#define PLAYERPOINT_H_
class playerpoint{
    public:
        playerpoint();
        playerpoint(vector<int>);
        void set_arr(vector<int>);
        void set_live(int);
        void set_s_live(int);
        void set_money(int);
        void set_flag(int);
        void set_bet(int);
        void set_insurance_bet(int);
        void set_double_flag(int);
        void set_point_sum(int);
        void set_gain(int);
        void set_intial_money(int);
        void set_surrender_flag(int);
        void set_had_ace(int);
        int get_live();
        int get_s_live();
        int get_money();
        int get_flag();
        int get_bet();
        int get_insurance_bet();
        int get_double_flag();
        int get_point_sum();
        int get_gain();
        int get_intial_money();
        int get_surrender_flag();
        int get_had_ace();
        vector<int> get_arr();
        void push(int);
        int top();
        void empty();
        void bank(int);
        void point_plus(int);
        int get_size();
        void bank_gain(int);

    private:
        int live;
        int s_live;
        int flag;
        int point_sum;
        int money;
        int bet;
        int insurance_bet;
        int double_flag;
        int gain;
        int intial_money;
        int surrender_flag;
        int had_ace;
        vector<int> arr;
};
#endif