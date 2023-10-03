using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy2Spawner : MonoBehaviour
{
    [SerializeField] GameObject Enemy2Prefab;

    Transform player;

    public static Enemy2Spawner Instance;

    public static int noOfEnemiesAlive = 0;

    //GameObject _parent;
    public PlayerMovement play;

    void Awake()
    {
        noOfEnemiesAlive = 0;
        Instance = GetComponent<Enemy2Spawner>();
        player = GameObject.FindGameObjectWithTag("Player").GetComponent<Transform>();
    }

    void Start()
    {
        StartCoroutine(Spawn());
    }

    IEnumerator Spawn()
    {
        if (noOfEnemiesAlive < 5)
        {
            List<Vector2> o = new List<Vector2>();
            Vector2 z;
            z.x = -7;
            z.y = -2;
            o.Add(z);
            z.x = 22;
            z.y = 6;
            o.Add(z);
            z.x = 3;
            z.y = 8;
            o.Add(z);
            z.x = 3;
            z.y = -3;
            o.Add(z);
            z.x = 22;
            z.y = -3;
            o.Add(z);
            z.x = 22;
            z.y = 6;
            o.Add(z);
            z.x = 12;
            z.y = 8;
            o.Add(z);
            z.x = 12;
            z.y = -3;
            o.Add(z);
            int ranX = Random.Range(0, 8);






            Vector3 spawnPosition = new Vector3(o[ranX].x, o[ranX].y-1, 0);
            GameObject enemy = Instantiate(Enemy2Prefab, spawnPosition, Quaternion.identity);
            enemy.tag = "Enemy2";
            noOfEnemiesAlive++;
        }

        yield return new WaitForSeconds(8);
        if (play.isAlive())
        {
            StartCoroutine(Spawn());
        }
    }
}
