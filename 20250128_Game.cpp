#include "20250128_Game.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

Game::Game()
    : user("あなた"), cpu("CPU") {
    // 得点カードを準備
    for (int i = -5; i <= 10; ++i) {
        if (i != 0) {
            scoreCards.emplace_back(i);
        }
    }
    shuffleScoreCards();

    // プレイヤーズカードを準備
    for (int i = 1; i <= 15; ++i) {
        user.addCard(Card(i));
        cpu.addCard(Card(i));
    }
}

void Game::shuffleScoreCards() {
    std::shuffle(scoreCards.begin(), scoreCards.end(), std::default_random_engine(static_cast<unsigned>(std::time(nullptr))));
}

void Game::playRound(int roundIndex) {
    Card currentScoreCard = scoreCards[roundIndex];
    std::cout << "\nラウンド " << roundIndex + 1 << ": 得点カード = " << currentScoreCard.getValue();

    // マイナス得点カードの場合の特別メッセージ
    if (currentScoreCard.getValue() < 0) {
        std::cout << " (残念！マイナス点です)";
    }
    std::cout << std::endl;

    // 手札を表示し、ユーザーがカードを選択
    user.showHand();
    Card userCard = user.playCard();

    // CPUがランダムでカードを選択
    Card cpuCard = cpu.playCard();

    // ユーザーとCPUのカードを表示
    std::cout << user.getName() << " が出したカード: " << userCard.getValue() << std::endl;
    std::cout << cpu.getName() << " が出したカード: " << cpuCard.getValue() << std::endl;

    // 勝敗を判定
    if (currentScoreCard.getValue() > 0) {
        // プラス得点の場合、大きいカードを出したプレイヤーが勝利
        if (userCard.getValue() > cpuCard.getValue()) {
            user.collectCard(currentScoreCard);
            std::cout << user.getName() << " がこのラウンドを勝ち取りました！" << std::endl;
        }
        else if (cpuCard.getValue() > userCard.getValue()) {
            cpu.collectCard(currentScoreCard);
            std::cout << cpu.getName() << " がこのラウンドを勝ち取りました！" << std::endl;
        }
        else {
            std::cout << "引き分けです！この得点カードは誰も獲得しません。" << std::endl;
        }
    }
    else {
        // マイナス得点の場合、小さいカードを出したプレイヤーが勝利
        if (userCard.getValue() < cpuCard.getValue()) {
            user.collectCard(currentScoreCard);
            std::cout << user.getName() << " がこのラウンドを引き取ってしまいました。" << std::endl;
        }
        else if (cpuCard.getValue() < userCard.getValue()) {
            cpu.collectCard(currentScoreCard);
            std::cout << cpu.getName() << " がこのラウンドを引き取ってしまいました。" << std::endl;
        }
        else {
            std::cout << "引き分けです！この得点カードは誰も獲得しません。" << std::endl;
        }
    }
}

void Game::playGame() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // CPU用乱数の初期化

    std::cout << "ゲームを開始します！\n" << std::endl;

    for (int i = 0; i < scoreCards.size(); ++i) {
        playRound(i);
    }

    // 最終結果の表示
    std::cout << "\nゲーム終了！\n" << std::endl;
    std::cout << user.getName() << " の総得点: " << user.getTotalScore() << std::endl;
    std::cout << cpu.getName() << " の総得点: " << cpu.getTotalScore() << std::endl;

    if (user.getTotalScore() > cpu.getTotalScore()) {
        std::cout << user.getName() << " の勝利です！おめでとうございます！" << std::endl;
    }
    else if (cpu.getTotalScore() > user.getTotalScore()) {
        std::cout << cpu.getName() << " の勝利です！残念でした。" << std::endl;
    }
    else {
        std::cout << "引き分けです！素晴らしい戦いでした！" << std::endl;
    }
}
