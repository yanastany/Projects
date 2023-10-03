using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;

public class Tutorial3 : MonoBehaviour
{
    public int x = 0;
    // Start is called before the first frame update
    public TextMeshProUGUI txt;
    public void NextLine()
    {
        x++;
    }
    // Update is called once per frame
    void Update()
    {
        if (x == 1)
        {
            txt.text = "The idiot's sittin' all alone, drownin' his sorrows at the salon in the city. His gang's gatherin' up there, but for now, you got yourself some precious time alone with him. ";
        }
        if (x == 2)
        {
            txt.text = "Make it count, partner. Aim true, shoot fast, and make sure that sorry son of a gun meets his maker. Good luck to ya, and may the winds of fortune be at your side.";

        }
        if (x == 3)
        {
            txt.text = "Hold your horses, partner! Got some news that'll put a smile on your face. By pressin' that trusty ol' number 3, you've unlocked the SNIPER.";
        }
        if (x == 4)
        {
            txt.text = " Now, listen up real good. This here rifle packs a punch like a stampede of wild horses, deliverin' more damage than a bull's horn. But remember, it's got lower ammo, so use it smart.";
        }
        if (x == 5)
        {
            txt.text = "Take your time, line up that shot, and let 'er fly when it counts. Keep your wits about ya, partner, and make every bullet count. Show 'em what a true sharpshooter can do!";
        }

        if (x == 6)
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
        }
    }
}
