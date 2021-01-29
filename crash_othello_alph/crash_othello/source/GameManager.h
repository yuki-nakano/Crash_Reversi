#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

class GameManager
{
private:
	GameManager();
	static GameManager* gameManager;

public:
	static void CreateInstance();
	static void DeleteInstance();

	static GameManager* GetInstance() { return gameManager; };

	void SetMaxPlayer(int maxPlayer_) { maxPlayer = maxPlayer_; };
	void SetPlayer1(int player_) { player_1 = player_; };
	void SetPlayer2(int player_) { player_2 = player_; };
	void SetPlayer3(int player_) { player_3 = player_; };
	void SetPlayer4(int player_) { player_4 = player_; };

	int GetMaxPlayer() { return maxPlayer; };
	int GetPlayer1() { return player_1; };
	int GetPlayer2() { return player_2; };
	int GetPlayer3() { return player_3; };
	int GetPlayer4() { return player_4; };


private:
	int maxPlayer;
	int player_1;
	int player_2;
	int player_3;
	int player_4;


};

#endif // !GAME_MANAGER_H
