using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Hpow2 : MonoBehaviour
{
    public GameObject ef;
    public Healthbarscript healthb;
    public SpriteRenderer rnd;
    public Score score;
    public bool resp = false;
    public float oldScore = 0;
    public GameObject player;
    private Canvas canvas;
    Collider2D m_Collider;


    private void Start()
    {
        m_Collider = GameObject.FindGameObjectWithTag("Tile2").GetComponent<Collider2D>();
    }

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
        PlayerMovement h = collision.GetComponent<PlayerMovement>();
        h.currentHealth = 100;
        healthb.setHealth(h.currentHealth);
        rnd.enabled = false;
        gameObject.GetComponent<Collider2D>().enabled = false;
        resp = false;


    }

    private void Update()
    {
        if (score.score % 3 == 0)
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

