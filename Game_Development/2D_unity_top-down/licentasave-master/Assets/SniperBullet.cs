using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SniperBullet : MonoBehaviour
{
    public GameObject hitef;
    void OnCollisionEnter2D(Collision2D collision)
    {

        if (collision.gameObject.CompareTag("Player") && gameObject.CompareTag("EnemyBullet"))
        {
            collision.gameObject.GetComponent<PlayerMovement>().TakeDamage(30);
            Destroy(gameObject);
        }
        else
        {
            Destroy(gameObject,0.5f);
        }
    }
}
