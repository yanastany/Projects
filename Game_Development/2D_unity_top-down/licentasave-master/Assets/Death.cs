using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;

public class Death : MonoBehaviour
{
    public GameObject ui;
    private Score Score;
    public static string menu = "Menu";
    
    public TMP_InputField inputName;

    public string playerName;
    // Start is called before the first frame update
    void Start()
    {
        ui.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        if (GameObject.FindGameObjectWithTag("Player").GetComponent<PlayerMovement>().currentHealth <= 0)
        {
            ui.SetActive(true);
            inputName.ActivateInputField();
            playerName = inputName.text;
            Score = GameObject.FindGameObjectWithTag("Canvas").GetComponent<Score>();         
            Time.timeScale = 0f;                
        }
    }

    public void retry()
    {        
            
            int a = PlayerPrefs.GetInt("HighScore1", 0);
            int b = PlayerPrefs.GetInt("HighScore2", 0);
            int c = PlayerPrefs.GetInt("HighScore3", 0);
            string a1 = PlayerPrefs.GetString("HS1Name", "");
            string b2 = PlayerPrefs.GetString("HS2Name", "");
            string c3 = PlayerPrefs.GetString("HS3Name", "");
            if (a < Score.score)
            {
                PlayerPrefs.SetInt("HighScore1", Score.score);
                PlayerPrefs.SetString("HS1Name", playerName);
                PlayerPrefs.SetInt("HighScore2", a);
                PlayerPrefs.SetString("HS2Name", a1);
                PlayerPrefs.SetInt("HighScore3", b);
                PlayerPrefs.SetString("HS3Name", b2);
            }
            else if (b < Score.score && a != Score.score)
            {
                PlayerPrefs.SetInt("HighScore2", Score.score);
                PlayerPrefs.SetString("HS2Name", playerName);
                PlayerPrefs.SetInt("HighScore3", b);
                PlayerPrefs.SetString("HS3Name", b2);
            }
            else if (c < Score.score && a != Score.score && b != Score.score)
            {
                PlayerPrefs.SetInt("HighScore3", Score.score);
                PlayerPrefs.SetString("HS3Name", playerName);
            }       
        SceneManager.LoadSceneAsync(SceneManager.GetActiveScene().buildIndex);
        Time.timeScale = 1f;
        

    }
    public void Home()
    {
        int a = PlayerPrefs.GetInt("HighScore1", 0);
        int b = PlayerPrefs.GetInt("HighScore2", 0);
        int c = PlayerPrefs.GetInt("HighScore3", 0);
        string a1 = PlayerPrefs.GetString("HS1Name", "");
        string b2 = PlayerPrefs.GetString("HS2Name", "");
        string c3 = PlayerPrefs.GetString("HS3Name", "");
        if (a < Score.score)
        {
            PlayerPrefs.SetInt("HighScore1", Score.score);
            PlayerPrefs.SetString("HS1Name", playerName);
            PlayerPrefs.SetInt("HighScore2", a);
            PlayerPrefs.SetString("HS2Name", a1);
            PlayerPrefs.SetInt("HighScore3", b);
            PlayerPrefs.SetString("HS3Name", b2);
        }
        else if (b < Score.score && a != Score.score)
        {
            PlayerPrefs.SetInt("HighScore2", Score.score);
            PlayerPrefs.SetString("HS2Name", playerName);
            PlayerPrefs.SetInt("HighScore3", b);
            PlayerPrefs.SetString("HS3Name", b2);
        }
        else if (c < Score.score && a != Score.score && b != Score.score)
        {
            PlayerPrefs.SetInt("HighScore3", Score.score);
            PlayerPrefs.SetString("HS3Name", playerName);
        }
        SceneManager.LoadScene(0);
    }
}
