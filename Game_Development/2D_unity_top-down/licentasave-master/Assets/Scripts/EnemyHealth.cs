using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EnemyHealth : MonoBehaviour
{

    [SerializeField] private Slider slider;
    [SerializeField] private Camera cam;
    [SerializeField] private Transform tr;
    [SerializeField] public Vector3 poz;

    public void UpdateHealth(float Health,float maxHealth)
    {
        slider.value = Health / maxHealth;
    }
   
    void Update()
    {
        transform.position = poz+tr.position  ;      
    }
}
