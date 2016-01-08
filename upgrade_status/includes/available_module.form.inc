<?php

/**
 * Build the settings form.
 */
function available_module_form() {
  $form = array();
  $form['border'] = array(
    '#type' => 'fieldset',
    '#title' => t('Module/Theme Upgrade Status Report'),
  );
  $form['border']['drupal_current_version'] = array(
    '#prefix' => "<div class ='markup'>",
    '#suffix' => "</div>",
    '#markup' => t('Current Drupal Core version is : Drupal ').VERSION,
    '#attributes' => array('class' => array('search-form')),

  );
  $form['border']['note'] = array(
    '#markup' => 'Provides upgrade available status only for enabled Modules and Themes.'
  );
  $form['border']['check_available'] = array(
    '#type' => 'select',
    '#title' => t('Upgrade to'),
    '#description' => t('Select a Drupal version to check Modules and Themes availability.'),
    '#default_value' => 8,
    '#options' => array(
          7 => 'Drupal 7',
         8 => 'Drupal 8',
       ),
    '#required' => TRUE,
    '#disabled' => TRUE,    //Now a days drupal 8 we going to using.
  );
    $result_display = available_modules();
    $form['border']['store'] = array(
        '#type' => 'value',
        '#value' => $result_display,
    );
    $form['border']['csv_download'] = array(
       '#type' => 'submit',
        '#value' => 'Download as CSV',
    );

    $form['result_border']['result'] = array(
    '#markup' => $result_display,
  );

  return $form;
}
function available_module_form_submit($form, &$form_state){
    $result = $form_state['values']['store'];

    drupal_add_http_header('Content-Type', 'text/csv; utf-8');
    drupal_add_http_header('Content-Disposition', 'attachment; filename=' . 'Available module');
    print $result;
    drupal_exit();
}

