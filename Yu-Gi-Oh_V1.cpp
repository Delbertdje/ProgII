#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Card {
public:
    string name;
    int attack;
    int defense;
    
    Card(string _name, int _attack, int _defense) : name(_name), attack(_attack), defense(_defense) {}
};

class Player {
public:
    string name;
    int lifePoints;
    vector<Card> hand;
    
    Player(string _name) : name(_name), lifePoints(8000) {}
    
    void drawCard(Card card) {
        hand.push_back(card);
    }
    
    void showHand() {
        cout << name << "'s hand:" << endl;
        for (const Card& card : hand) {
            cout << card.name << " (" << card.attack << "/" << card.defense << ")" << endl;
        }
    }
    
    void takeDamage(int damage) {
        lifePoints -= damage;
        cout << name << " Levou " << damage << " de Dano. Life points: " << lifePoints << endl;
    }
};

int main() {
    // Criação de dois jogadores
    Player player1("Yugi Muto");
    Player player2("Jaden Yuki");
    
    // Criação de Cartas
    Card E_HeroNeos("Elemetal Hero Neos", 2500, 2000);
    Card DarkMagician("Dark Magician", 2500, 2100);
    Card BlueEyesWhiteDragon("Blue-Eyes White Dragon", 3000, 2500);
    Card RedEyesBlackDragon("Red-Eyes Black Dragon", 2400, 2000);
    
    // Distribuição inicial de cartas
    player1.drawCard(DarkMagician);
    player1.drawCard(BlueEyesWhiteDragon);
    player2.drawCard(RedEyesBlackDragon);
    player2.drawCard(E_HeroNeos);
    
    // Exibe as mãos dos jogadores
    player1.showHand();
    player2.showHand();
    
    // Simula um ataque
    player1.takeDamage(player2.hand[1].attack);
    player2.takeDamage(player1.hand[1].attack);
    
    return 0;
}