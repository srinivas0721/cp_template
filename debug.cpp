#include <bits/stdc++.h>
using namespace std;

// ----------- DEBUG PRINT BASES -----------

template <typename T>
typename enable_if<is_arithmetic<T>::value>::type
_print(const T &x) { cerr << x; }
void _print(const string &s) { cerr << '"' << s << '"'; }
void _print(const char &c) { cerr << '\'' << c << '\''; }
void _print(const bool &b) { cerr << (b ? "true" : "false"); }
template <typename T1, typename T2>
void _print(const pair<T1, T2> &p) {
    cerr << "[";
    _print(p.first); cerr << ", "; _print(p.second);
    cerr << "]";
}
template <typename... Ts, size_t... Is>
void _print_tuple_impl(const tuple<Ts...> &t, index_sequence<Is...>) {
    ((cerr << (Is ? ", " : ""), _print(get<Is>(t))), ...);
}
template <typename... Ts>
void _print(const tuple<Ts...> &t) {
    cerr << "[";
    _print_tuple_impl(t, index_sequence_for<Ts...>{});
    cerr << "]";
}
template <typename K, typename V>
void _print(const map<K, V> &m) {
    cerr << "[";
    bool first = true;
    for (auto &kv : m) {
        if (!first) cerr << ", ";
        cerr << "{";
        _print(kv.first);
        cerr << ": ";
        _print(kv.second);
        cerr << "}";
        first = false;
    }
    cerr << "]";
}
template <typename T>
typename enable_if<
    !is_same<decay_t<T>, string>::value &&
    !is_arithmetic<decay_t<T>>::value &&
    !is_same<decay_t<T>, map<typename T::key_type, typename T::mapped_type>>::value
>::type
_print(const T &x) {
    cerr << "[";
    bool first = true;
    for (auto &i : x) {
        if (!first) cerr << ", ";
        _print(i);
        first = false;
    }
    cerr << "]";
}
#define debug(x) cerr << #x << " = ", _print(x), cerr << "\n"
// ----------- DEBUG MACRO -----------

#define dbg(x) cerr << #x << " = ", _print(x), cerr << "\n"

int main() {
    vector<int> v = {1, 2, 3};
    vector<vector<int>> vv = {{1, 2}, {3, 4}};
    map<int, vector<pair<int, int>>> mp = {
        {1, {{2, 3}, {4, 5}}},
        {2, {{6, 7}}}
    };
    pair<int, string> pr = {42, "hello"};

    dbg(v);
    dbg(vv);
    dbg(mp);
    dbg(pr);
    dbg(make_tuple(1, "abc", 3.14));
}
