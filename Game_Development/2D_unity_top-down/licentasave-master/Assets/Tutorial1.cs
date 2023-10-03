using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;

public class Tutorial1 : MonoBehaviour
{   public int x=0;
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
            txt.text = "Well, partner, there's a notorious outlaw by the name of Jack McCallister causin' a ruckus in these parts. He's been terrorizin' the good folks of Outlaw Outpost and it's high time someone put an end to his mischief.";
        }
        if (x == 2)
        {
            txt.text = "I need you to track him down, partner, and take him out. Word has it he's got a whole gang of bandits with him, so it won't be an easy task. But if anyone can get the job done, it's you.";

        }
        if (x == 3)
        {
            txt.text = "Here is some help:" + "\r\n" + "WASD to move" + "\r\n" + "Right click to shoot' em up" + "\r\n" + "You have the minimap on the right, ammo count in the middle  and Healthbar on the left";
        }
        if (x == 4)
        {
            txt.text = " That's what I like to hear, partner! Remember, you re doin the right thing. Good luck out there, and may your aim be true. Ride hard, ride fast, and return triumphant. Outlaw Outpost is countin' on ya!";
        }
        if (x == 5)
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
        }
        
    }
}
