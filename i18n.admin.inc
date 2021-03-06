<?php

/**
 * @file
 * Extended multilanguage administration and module settings UI.
 */

/**
 * Form builder function.
 * 
 * TO DO: Add exclude paths for content selection
 * Some options have been removed from previous versions:
 * - Languages are now taken from locale module unless defined in settings file
 * - Language dependent tables are authomatically used if defined in settings file
 */
function i18n_admin_settings() {
  // Content selection options
  $form['selection'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content selection'),
    //'#collapsible' => TRUE,
    //'#collapsed' => TRUE,
  );
  $form['selection']['i18n_selection_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Content selection mode'),
    '#default_value' => variable_get('i18n_selection_mode', 'simple'),
    '#options' => _i18n_selection_mode(),
    '#description' => t('Determines which content to show depending on language.'),
  );
  return system_settings_form($form);
}

// List of selection modes
function _i18n_selection_mode(){
  return array(
    'simple' => t('Only current language and no language'),
    'mixed' => t('Only current and default languages and no language'),
    'default' => t('Only default language and no language'),    
    'strict' => t('Only current language'),
    'off' => t('All content. No language conditions apply'),    
  );
}

