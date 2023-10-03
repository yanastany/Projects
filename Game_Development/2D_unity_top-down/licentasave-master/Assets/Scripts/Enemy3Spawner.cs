using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy3Spawner : MonoBehaviour
{
    [SerializeField] GameObject Enemy1Prefab;

    Transform player;

    public static Enemy3Spawner Instance;

    public static int noOfEnemiesAlive = 0;

   // GameObject _parent;
    public PlayerMovement play;

    void Awake()
    {
        noOfEnemiesAlive = 0;
        Instance = GetComponent<Enemy3Spawner>();
        player = GameObject.FindGameObjectWithTag("Player").GetComponent<Transform>();
    }

    void Start()
    {
        //_parent = GameObject.Find("Enm");
        StartCoroutine(Spawn());
    }

    IEnumerator Spawn()
    {
        if (noOfEnemiesAlive < 3)
        {
            List<Vector2> o = new List<Vector2>();
            Vector2 z;
            z.x = -7;
            z.y = -2;
            o.Add(z);
            z.x = -5;
            z.y = -7;
            o.Add(z);
            z.x = 3;
            z.y = 8;
            o.Add(z);
            z.x = 3;
            z.y = -4;
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






            Vector3 spawnPosition = new Vector3(o[ranX].x+1, o[ranX].y, 0);

            GameObject enemy = Instantiate(Enemy1Prefab, spawnPosition, Quaternion.identity);



            enemy.tag = "Enemy3";


            noOfEnemiesAlive++;
        }

        yield return new WaitForSeconds(12);

        if (play.isAlive())
        {
            StartCoroutine(Spawn());
        }
    }
}
