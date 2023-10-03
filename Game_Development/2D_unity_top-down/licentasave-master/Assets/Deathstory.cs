using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Deathstory : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject ui;
    
    public static string menu = "Menu";

    

    
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
           
            Time.timeScale = 0f;
        }
    }

    public void retry()
    {
        
        
        SceneManager.LoadSceneAsync(SceneManager.GetActiveScene().buildIndex);
        Time.timeScale = 1f;


    }
    public void Home()
    {
        SceneManager.LoadScene(0);
    }
}
