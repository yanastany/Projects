using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletShootgun : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject hitef;
    void OnCollisionEnter2D(Collision2D collision)
    {

        if (collision.gameObject.CompareTag("Player") && gameObject.CompareTag("EnemyBullet"))
        {
            collision.gameObject.GetComponent<PlayerMovement>().TakeDamage(10);
            Destroy(gameObject);
        }
        else
        {
            Destroy(gameObject, 2f);
        }
    }


}
