using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;

public class Tutorial4 : MonoBehaviour
{
    public int x = 0;
    // Start is called before the first frame update
    public TextMeshProUGUI txt;
    //public TextMeshPro home;
    public GameObject continueButton;
    
    public void Start()
    {
        continueButton.SetActive(false);
    }
    public void NextLine()
    {
        x++;
    }
    public void Home()
    {
        SceneManager.LoadScene(0);
    }
    // Update is called once per frame
    void Update()
    {
        if (x == 1)
        {
            txt.text = "You, my friend, are a true gunslinger, a force to be reckoned with. I couldn't be prouder of ya, seein' you bring justice to this lawless land. ";
        }
        if (x == 2)
        {
            txt.text = "You've earned yourself a place in cowboy legend, and I reckon this town will forever remember the day you rid us of that varmint. Well done, cowboy. Well done, indeed.";
            
            continueButton.SetActive(true);
        }
        if (x == 3)
        {
            txt.text = "Well, dang it all! The gang done caught up to us, partner. But fear not, 'cause now's the time to show 'em what a true gunslinger's made of!";
        }
        if (x == 4)
        {
            txt.text = "Strap on your iron, steady your aim, and let them varmints taste the lead. We ain't backin' down, not one inch. It's time to unleash the fury and make 'em regret ever crossin' paths with us. ";
          } 
        if (x == 5)
            {
                txt.text = "Ride hard, shoot straight, and let 'em witness the raw power of a cowboy who won't be tamed!";
            }

           
        if (x == 6)
            {
                SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
            }
        
    }
}
