using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ammopow : MonoBehaviour
{
    public GameObject ef;
    public Healthbarscript healthb;
    public SpriteRenderer rnd;
    public Score score;
    public bool resp = false;
    public float oldScore = 0;
    public GameObject player;
    public Shooting shooting;
   


    void OnTriggerEnter2D(Collider2D collision)
    {
        Debug.Log(collision.tag);
        if (collision.CompareTag("Player"))
        {
            Pickup(collision);
        }

    }

    void Pickup(Collider2D collision)
    {
        GameObject ef1 = Instantiate(ef, transform.position, transform.rotation);
        Destroy(ef1, 0.3f);
        Shooting h = collision.GetComponent<Shooting>();
        h.noOfBulletsPistol = h.noOfBulletsPistol + 20;
        h.noOfBulletssg = h.noOfBulletssg + 30;
        h.noOfBulletssnip = h.noOfBulletssnip + 10;
        rnd.enabled = false;
        gameObject.GetComponent<Collider2D>().enabled = false;
        resp = false;
    }

    private void Update()
    {

        if (score.score % 5 == 0 && score.score > 0 && resp == false && score.score != oldScore)
        {

            
            resp = true;
            Transform playerPos = player.GetComponent<Transform>();
            gameObject.GetComponent<Collider2D>().enabled = true;
            rnd.enabled = true;
            oldScore = score.score;         
        }
        else if (score.score == 0)
        {
            rnd.enabled = false;
            gameObject.GetComponent<Collider2D>().enabled = false;
        }

    }
}
