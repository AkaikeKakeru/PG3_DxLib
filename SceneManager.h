#pragma once

class SceneManager final {
public :
    enum sceneNom{
        title_num,
        newGame_num,
        gamePlay_num,
        gameClear_num
    };

public:
    void Update();

    void Draw();

private:
    /// <summary>
    /// シーン変更
    /// </summary>
    /// <param name="nextSceneNom">次のシーン番号</param>
    void ChangeScene(int nextSceneNom){ nowSceneNom_ = nextSceneNom; };

private:
    int nowSceneNom_ = title_num;
private:
    //コンストラクタをprivateにする
    SceneManager() = default;
    //デストラクタをprivateにする
    ~SceneManager();

public:
    //コピーコンストラクタを無効にする
    SceneManager(const SceneManager& obj) = delete;
    //代入演算子を無効にする
    SceneManager& operator = (const SceneManager& obj) = delete;

    static SceneManager* GetInstance();
};
