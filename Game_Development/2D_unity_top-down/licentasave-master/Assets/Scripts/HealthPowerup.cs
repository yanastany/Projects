using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HealthPowerup : MonoBehaviour
{

    public GameObject ef;
    public Healthbarscript healthb;
    public SpriteRenderer rnd;
    public Score score;
    public bool resp = false;
    public float oldScore = 0;
    public GameObject player;
    private Canvas canvas;
    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.CompareTag("Player"))
        {
            Pickup(collision);
        }
    }

    void Pickup(Collider2D collision)
    {
        //Instantiate(ef, transform.position, transform.rotation);
        PlayerMovement h = collision.GetComponent<PlayerMovement>();
        h.currentHealth = 100;
        healthb.setHealth(h.currentHealth);
        rnd.enabled = false;
        gameObject.GetComponent<Collider2D>().enabled = false;
        resp = false;
        Destroy(gameObject);

    }
}
