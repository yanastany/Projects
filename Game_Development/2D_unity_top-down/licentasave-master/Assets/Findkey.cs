using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using TMPro;

public class Findkey : MonoBehaviour
{
    public SpriteRenderer rnd;
    public Score score;
    public TextMeshProUGUI txt;
    public int x;
    // Start is called before the first frame update
    void OnTriggerEnter2D(Collider2D collision)
    {
        Debug.Log(collision.tag);
        if (collision.CompareTag("Player"))
        {
            Pickup();
        }
        
    }

    void Pickup()
    {
        //Instantiate(ef, transform.position, transform.rotation);

        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);

    }
    private void Update()
    {
        if (score.score >=x && score.score > 0)
        {
            
            txt.text =  "Find the key to advance";


            rnd.enabled = true;
            gameObject.GetComponent<Collider2D>().enabled = true;



        }
        else if (score.score <= x-1)
        {

            rnd.enabled = false;
            gameObject.GetComponent<Collider2D>().enabled = false;
        }

    }
}
