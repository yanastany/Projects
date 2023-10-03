using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MiniMapScript : MonoBehaviour
{
    
    public Transform player;

    void LateUpdate()
    {
        Vector3 np = player.position;
        np.z = transform.position.z;
        transform.position = np;   
    }
}
