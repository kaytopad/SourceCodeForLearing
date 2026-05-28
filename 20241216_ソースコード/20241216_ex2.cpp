#include <iostream>
#include <vector>
#include <memory> // スマートポインタのため

// 基底クラス
class Character {
public:
    virtual void update() = 0; // 純粋仮想関数
    virtual void render() const = 0; // 純粋仮想関数
    virtual ~Character() = default;
};

// プレイヤークラス
class Player : public Character {
public:
    void update() override {
        std::cout << "プレイヤーが移動している...\n";
    }
    void render() const override {
        std::cout << "プレイヤーを描画\n";
    }
};

// 敵キャラクタークラス
class Enemy : public Character {
public:
    void update() override {
        std::cout << "敵がプレイヤーを追いかけている...\n";
    }
    void render() const override {
        std::cout << "敵を描画\n";
    }
};

// NPCキャラクタークラス
class NPC : public Character {
public:
    void update() override {
        std::cout << "NPCが話しかけている...\n";
    }
    void render() const override {
        std::cout << "NPCを描画\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Character>> characters;

    // キャラクターを動的に追加
    characters.push_back(std::make_unique<Player>());
    characters.push_back(std::make_unique<Enemy>());
    characters.push_back(std::make_unique<NPC>());

    // ゲームループの一部
    for (auto& character : characters) {
        character->update();
        character->render();
    }

    return 0;
}
