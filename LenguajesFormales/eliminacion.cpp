#include <bits/stdc++.h>
using namespace std;

struct Grammar {
    map<char, vector<string>> prod; // producciones: A -> lista de alternativas
    vector<char> order;             // orden de no terminales
    set<char> used;                 // no terminales usados
};

char nextNonTerminal(set<char>& usados) {
    for(char c='Z'; c>='A'; c--) {   // recorrer al revés
        if(!usados.count(c)) {
            usados.insert(c);
            return c;
        }
    }
    throw runtime_error("No quedan no terminales disponibles");
}


void eliminateImmediateLeftRecursion(char A, Grammar& G) {
    vector<string> alpha, beta;
    for(auto& rhs : G.prod[A]) {
        if(!rhs.empty() && rhs[0] == A) {
            alpha.push_back(rhs.substr(1)); // quitar A inicial
        } else {
            beta.push_back(rhs);
        }
    }

    if(alpha.empty()) return; // no hay recursión

    char newNT = nextNonTerminal(G.used);
    vector<string> newBeta, newAlpha;

    // A -> beta newNT
    for(auto& b : beta) {
        if(b == "e") newBeta.push_back(string(1,newNT));
        else newBeta.push_back(b + string(1,newNT));
    }

    // newNT -> alpha newNT | e
    for(auto& a : alpha) {
        newAlpha.push_back(a + string(1,newNT));
    }
    newAlpha.push_back("e");

    G.prod[A] = newBeta;
    G.prod[newNT] = newAlpha;
    G.order.push_back(newNT);
}

void eliminateLeftRecursion(Grammar& G) {
    int n = G.order.size();
    for(int i=0; i<n; i++) {
        char Ai = G.order[i];
        // sustituir recursión indirecta con anteriores
        for(int j=0; j<i; j++) {
            char Aj = G.order[j];
            vector<string> newRhs;
            for(auto& rhs : G.prod[Ai]) {
                if(!rhs.empty() && rhs[0] == Aj) {
                    // reemplazar Ajγ por (alternativas de Aj)γ
                    string gamma = rhs.substr(1);
                    for(auto& rhsAj : G.prod[Aj]) {
                        newRhs.push_back(rhsAj + gamma);
                    }
                } else {
                    newRhs.push_back(rhs);
                }
            }
            G.prod[Ai] = newRhs;
        }
        // eliminar recursión inmediata
        eliminateImmediateLeftRecursion(Ai, G);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; // número de casos
    for(int c=0; c<n; c++) {
        int k; 
        cin >> k;
        Grammar G;
        for(int i=0; i<k; i++) {
            char lhs;
            string arrow, rhsLine;
            cin >> lhs >> arrow;
            G.order.push_back(lhs);
            G.used.insert(lhs);

            getline(cin, rhsLine);
            stringstream ss(rhsLine);
            string alt;
            while(ss >> alt) {
                if(alt=="e") G.prod[lhs].push_back("e");
                else G.prod[lhs].push_back(alt);
            }
        }

        eliminateLeftRecursion(G);

        for(char A : G.order) {
            cout << A << " -> ";
            for(size_t i=0; i<G.prod[A].size(); i++) {
                if(i) cout << " ";
                cout << G.prod[A][i];
            }
            cout << "\n";
        }
        if(c != n-1) cout << "\n";
    }
    return 0;
}
