#pragma once

class SceneManager final {
public :
    //シーン番号
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
    void ChangeScene(int nextSceneNom) ;

    /// <summary>
    /// シーン番号取得
    /// </summary>
    /// <param name="nowSceneNom">シーン番号</param>
    /// <returns>シーン番号</returns>
    int GetSceneNom(int nowSceneNom) { return nowSceneNom_; }

private:
    //シーン名
    const char* sceneName = "Title";
    //テキストの色
    unsigned int color = 0;
    //今のシーン番号
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
