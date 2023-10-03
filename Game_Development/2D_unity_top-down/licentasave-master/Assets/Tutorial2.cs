using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;
public class Tutorial2 : MonoBehaviour
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
            txt.text = "Well, reckon, partner, hate to break it to ya, but there are still more challenges awaitin' ya on the horizon. But worry not, 'cause ol' me has a trick or two up my sleeve for ya, cowpoke!";
        }
        if (x == 2)
        {
            txt.text = "First off, word on the wind is they've hired a bunch of no-good varmints packin' shotguns. They may be lookin' for a closer range fight, sprayin' more bullets than a rattlesnake shakes its tail.";

        }
        if (x == 3)
        {
            txt.text = "But fear not, partner, 'cause I've been cookin' up somethin' special just for you.";
        }
        if (x == 4)
        {
            txt.text = " Listen up, cowpoke! I've got some help comin' your way. Keep your eyes peeled, 'cause them medkits and speedboosts will be droppin' from the heavens like a summer rain after every three kills you notch on your belt.";
        }
        if (x == 5)
        {
            txt.text ="And if you're runnin' low on ammo, don't you worry none, 'cause a fresh stash will be yours every five kills. Load up, stay sharp, and keep ridin' into that sunset!" ;
        }

        if (x == 6)
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
        }
    }
}
