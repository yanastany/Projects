using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScriptShop : MonoBehaviour
{
    public static bool Gameinshop = false;

    public GameObject shopMenu;
    // Start is called before the first frame update
    bool x = false;
    public void OnTriggerStay2D(Collider2D collider)
    {
        if (collider.CompareTag("Player")){
            x = true;
        }   
    }
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Alpha9) && x==true)
        {
            shop();
        }
    }

    public void shop()
    {
        shopMenu.SetActive(true);
        Time.timeScale = 0f;
        Gameinshop = true;
    }
    public void Resumeshop()
    {
        shopMenu.SetActive(false);
        Time.timeScale = 1f;
        Gameinshop = false;

    }

}
