using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletSniper : MonoBehaviour
{
    public float TimeToLive = 2f;
    public int dmgsnip = 40;
    private void Start()
    {
        Destroy(gameObject, TimeToLive);
    }
    // Start is called before the first frame update
    public GameObject hitef;
    void OnCollisionEnter2D(Collision2D collision)
    {
        if (!collision.gameObject.CompareTag("Player") && !gameObject.CompareTag("Bullet"))
        {
            GameObject ef = Instantiate(hitef, transform.position, Quaternion.identity);
            Destroy(ef, 1f);
            Destroy(gameObject);
        }

        if (collision.gameObject.CompareTag("Enemy") && gameObject.CompareTag("Bullet"))
        {
            collision.gameObject.GetComponent<EnemyShooting>().TakeDamage(dmgsnip);
            Destroy(gameObject);
        }
        if (collision.gameObject.CompareTag("Enemy2") && gameObject.CompareTag("Bullet"))
        {
            collision.gameObject.GetComponent<EnemySgootgun>().TakeDamage(dmgsnip);
            Destroy(gameObject);
        }
        if (collision.gameObject.CompareTag("Enemy3") && gameObject.CompareTag("Bullet"))
        {
            collision.gameObject.GetComponent<EnemySniper>().TakeDamage(dmgsnip);
            Destroy(gameObject);
        }
        if (collision.gameObject.CompareTag("Enemylvl1") && gameObject.CompareTag("Bullet"))
        {
            collision.gameObject.GetComponent<Enemy1lvl1>().TakeDamage(dmgsnip);
            Destroy(gameObject);
        }
        if (collision.gameObject.CompareTag("Enemy2lvl2") && gameObject.CompareTag("Bullet"))
        {
            collision.gameObject.GetComponent<Enemy2Lvl2>().TakeDamage(dmgsnip);
            Destroy(gameObject);
        }

    }
    public void dmgupt(int x)
    {
        dmgsnip = dmgsnip + x;
        
    }
}
