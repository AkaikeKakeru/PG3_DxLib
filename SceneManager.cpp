#include "SceneManager.h"
#include "DxLib.h"
#include <stdio.h>

void SceneManager::Update(){
    char c = 0;

    int next = nowSceneNom_+1;

    if (next > gameClear_num) {
        next = title_num;
    }

    ChangeScene(next);
}

void SceneManager::Draw() {
    color = GetColor(200, 200, 200);

    DrawFormatString(
        10,10, color,
        "Scene : %s",
        sceneName);

    DrawFormatString(
        10,40, color,
        "SceneNum : %d\nPress SPACE to Change Screen",
        nowSceneNom_);
}

void SceneManager::ChangeScene(int nextSceneNom){
    nowSceneNom_ = nextSceneNom; 

    switch (nowSceneNom_) {
    case title_num:
        SetBackgroundColor(0,0,0);
        sceneName = "Title";
        break;

    case newGame_num:
        SetBackgroundColor(180,0,0);
        sceneName = "NewGame";
        break;

    case gamePlay_num:
        SetBackgroundColor(0,0,180);
        sceneName = "GamePlay";
        break;

    case gameClear_num:
        SetBackgroundColor(0,180,0);
        sceneName = "GameClear";
        break;

    default:
        nowSceneNom_ = title_num;
        sceneName = "Title";
        break;
    }
};

SceneManager::~SceneManager(){
}

SceneManager* SceneManager::GetInstance() {
    //関数内でstatic変数として宣言
    static SceneManager instance;
    return &instance;
}
