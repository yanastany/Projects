using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class PauseMenu : MonoBehaviour
{
    // Start is called before the first frame update
    

    public GameObject pauseMenu;

    public static bool Gameispaused = false;
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            if (Gameispaused)
            { 
                Resume();
            }
            else
            {
                Pause();
            }
        }
    }
    void Pause()
    {
       pauseMenu.SetActive(true);
        Time.timeScale = 0f;
        Gameispaused = true;
    }
    public void Resume()
    { 
        pauseMenu.SetActive(false);
        Time.timeScale = 1f;
        Gameispaused =false;
        
    }
    public void Home()
    {
        SceneManager.LoadScene(0);
    }
}
