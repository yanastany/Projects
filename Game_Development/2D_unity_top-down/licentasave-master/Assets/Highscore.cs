using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class Highscore : MonoBehaviour
{
    public TextMeshProUGUI text;
    void Start()
    {
        text.text = PlayerPrefs.GetString("HS1Name", "Anonim") + ": " + PlayerPrefs.GetInt("HighScore1", 0) + " Points" + 
            "\r\n"+ PlayerPrefs.GetString("HS2Name", "Anonim") + ": " + PlayerPrefs.GetInt("HighScore2", 0) + " Points" + 
            "\r\n"+ PlayerPrefs.GetString("HS3Name", "Anonim") +": " + + PlayerPrefs.GetInt("HighScore3", 0) + " Points";
    }

    public void ResetHighscore()
    {
        PlayerPrefs.DeleteKey("HighScore1");
        PlayerPrefs.DeleteKey("HighScore2");
        PlayerPrefs.DeleteKey("HighScore3");
        PlayerPrefs.DeleteKey("HS1Name");
        PlayerPrefs.DeleteKey("HS2Name");
        PlayerPrefs.DeleteKey("HS3Name");

        text.text = PlayerPrefs.GetString("HS1Name", "Anonim") + ": " + PlayerPrefs.GetInt("HighScore1", 0) + " Points" + 
            "\r\n" + PlayerPrefs.GetString("HS2Name", "Anonim") + ": " + PlayerPrefs.GetInt("HighScore2", 0) + " Points" + 
            "\r\n" + PlayerPrefs.GetString("HS3Name", "Anonim") +": " + +PlayerPrefs.GetInt("HighScore3", 0) + " Points";
    }

}
