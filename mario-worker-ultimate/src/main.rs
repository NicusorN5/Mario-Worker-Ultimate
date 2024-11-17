use bevy::prelude::*;

#[derive(Component)]
struct MyCameraMarker;

fn setup_camera(mut commands: Commands, asset_server: Res<AssetServer>) {
    commands.spawn((
        Camera2dBundle {
            transform: Transform::from_xyz(100.0, 200.0, 0.0),
            ..default()
        },
        MyCameraMarker,
    ));

    commands.spawn(SpriteBundle {
        texture: asset_server.load("MarioWorkerUltimate.png"),
        transform 
        ..default()
    });

}

fn main() {
    let asset_plugin = AssetPlugin{ 
        file_path : "Data".to_string(),
        processed_file_path : "Data".to_string(),
        watch_for_changes_override : None,
        mode : AssetMode::Processed,
        meta_check : bevy::asset::AssetMetaCheck::Always
    };

    App::new()
    .add_plugins(DefaultPlugins.build().set(asset_plugin))
    .add_systems(Startup, setup_camera)
    .run();
}
