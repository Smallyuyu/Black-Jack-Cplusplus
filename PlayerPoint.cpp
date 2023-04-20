#include <iostream>
#include <vector>
#include "playerpoint.h"

playerpoint::playerpoint(){
    vector<int> arr1;
    set_arr(arr1);
    set_live(1);
    set_money(10000);
    set_flag(0);
    set_bet(0);
    set_insurance_bet(0);
    set_double_flag(0);
    set_point_sum(0);
    set_s_live(1);
    set_gain(0);
    set_intial_money(10000);
    set_surrender_flag(0);
    set_had_ace(0);
}

playerpoint::playerpoint(vector<int> arr1){
    set_arr(arr1);
    set_live(1);
    set_money(10000);
    set_flag(0);
    set_bet(0);
    set_insurance_bet(0);
    set_double_flag(0);
    set_point_sum(0);
    set_s_live(1);
    set_gain(0);
    set_intial_money(10000);
    set_surrender_flag(0);
    set_had_ace(0);
}

void playerpoint::set_live(int live1){
    live = live1;
}

void playerpoint::set_s_live(int sl){
    s_live = sl;
}

void playerpoint::set_money(int money1){
    money = money1;
}

void playerpoint::set_flag(int flag1){
    flag = flag1;
}

void playerpoint::set_bet(int bet1){
    bet = bet1;
}

void playerpoint::set_insurance_bet(int ib){
    insurance_bet = ib;
}

void playerpoint::set_double_flag(int df){
    double_flag = df;
}

void playerpoint::set_point_sum(int ps){
    point_sum = ps;
}

void playerpoint::set_gain(int gn){
    gain = gn;
}

void playerpoint::set_intial_money(int im){
    intial_money = im;
}

void playerpoint::set_surrender_flag(int sf){
    surrender_flag = sf;
}

void playerpoint::set_had_ace(int ha){
    had_ace = ha;
}

int playerpoint::get_live(){
    return live;
}

int playerpoint::get_s_live(){
    return s_live;
}

int playerpoint::get_money(){
    return money;
}

int playerpoint::get_flag(){
    return flag;
}

int playerpoint::get_bet(){
    return bet;
}

int playerpoint::get_insurance_bet(){
    return insurance_bet;
}

int playerpoint::get_double_flag(){
    return double_flag;
}

int playerpoint::get_point_sum(){
    return point_sum;
}

int playerpoint::get_gain(){
    return gain;
}

int playerpoint::get_intial_money(){
    return intial_money;
}

int playerpoint::get_surrender_flag(){
    return surrender_flag;
}

int playerpoint::get_had_ace(){
    return had_ace;
}

void playerpoint::set_arr(vector<int> arr1){
    arr = arr1;
}

vector<int> playerpoint::get_arr(){
    return arr;
}

void playerpoint::push(int num){
    arr.resize(arr.size() + 1);
    arr[arr.size() - 1] = num;
}

int playerpoint::top(){
    return arr[arr.size() - 1];
}

void playerpoint::empty(){
    arr.clear();
}

void playerpoint::bank(int money1){
    money = money + money1;
}

void playerpoint::point_plus(int pp){
    point_sum = point_sum + pp;
}

int playerpoint::get_size(){
    return arr.size();
}

void playerpoint::bank_gain(int bg){
    gain = gain + bg;
}